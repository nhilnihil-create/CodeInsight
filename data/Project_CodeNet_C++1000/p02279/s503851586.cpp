#include<iostream>
using namespace std;
#define EMPTY -1
const int N = 100005;

struct Node{
    int parent, leftChild, rightBrother;
};
Node node[N];
int depth[N];

void getDepth(int nowId, int nowDepth){//递归求深度
    depth[nowId] = nowDepth;
    if(node[nowId].leftChild!=EMPTY){
        getDepth(node[nowId].leftChild, nowDepth+1);//左子节点深度+1
    }
    if(node[nowId].rightBrother!=EMPTY){
        getDepth(node[nowId].rightBrother, nowDepth);//右兄弟节点深度设为相同
    }
}

void printNode(int id){
    int next;
    cout<<"node "<<id<<": "
        <<"parent = "<<node[id].parent<<", "
        <<"depth = "<<depth[id]<<", ";
        if(node[id].parent==EMPTY){
            cout<<"root, ";
        }else if(node[id].leftChild!=EMPTY){
            cout<<"internal node, ";
        }else{
            cout<<"leaf, ";
        }
        next=node[id].leftChild;
        bool first = true;
        cout<<"[";
        while(next!=EMPTY){
            if(first){
                first = false;
            }else{
                cout<<", ";
            }
            cout<<next;
            next=node[next].rightBrother;//节点位置后移
        }
        cout<<"]"<<endl;
}

int main(){
    int n;
    cin>>n;
    for(int i=0; i<n; i++){//初始化
        node[i].parent = node[i].leftChild = node[i].rightBrother=EMPTY;
    }
    for(int i=0;i<n;i++){//创建树
        int flag, id;
        cin>>id>>flag;
        for(int j=0, nowId;j<flag;j++){
            if(j==0){//指定当前节点的左子节点
                cin>>nowId;
                node[id].leftChild = nowId;//指定父节点的左子节点
            }else{
                int temp;
                cin>>temp;
                node[nowId].rightBrother = temp;//指定当前节点的右兄弟节点
                nowId=temp;//当前节点索引后移
            }
            node[nowId].parent = id;//指定父节点
        }
    }
    int root;
    for(int i = 0;i<n;i++){//寻找根节点
        if(node[i].parent==EMPTY){
            root = i;
        }
    }
    getDepth(root, 0);//根节点深度为0
    for(int i=0;i<n;i++){
        printNode(i);
    }
    return 0;
}

