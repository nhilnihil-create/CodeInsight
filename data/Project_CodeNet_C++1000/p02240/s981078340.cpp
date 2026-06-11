#include<iostream>
#define N 100001
using namespace std;

int father[N];
int findfather(int i){
    while(father[i]!=i){
        i=father[i];
    }
    return i;
}
void changeGroup(int a,int b){
    // merge b t a
    int fa=findfather(a);
    int fb=findfather(b);
    father[fb]=fa;
}

int main(){
    int n,m,q;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++) father[i]=i;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        changeGroup(a,b);
    }
    cin>>q;
    for(int i=0;i<q;i++){
        cin>>a>>b;
        if(findfather(a)==findfather(b)){
            cout<<"yes"<<endl;
        }else
            cout<<"no"<<endl;
    }
    return 0;
}

