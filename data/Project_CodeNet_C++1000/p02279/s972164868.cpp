#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

class vertex{
    public:
    int node;
    int parent = -1;
    int depth;
    vector<int> children;
};
bool operator<(const vertex &a, const vertex &b){
    return a.node<b.node;
}

int main(){
    int n;
    vertex v[100000];
    cin >> n;
    for(int i=0;i<n;i++){
        int id, k;
        cin >> id >> k;
        v[i].node=id;
        for(int j=0;j<k;j++){
            int c;
            cin >> c;
            v[i].children.push_back(c);
        }
    }
    sort(v, v+n);
    for(int i=0;i<n;i++){
        for(int x:v[i].children) v[x].parent=i;
    }
    for(int i=0;i<n;i++){
        if(v[i].parent==-1){
            v[i].depth=0;
            queue<int> q;
            for(int x:v[i].children) q.push(x);
            while(!q.empty()){
                int t=q.front();
                q.pop();
                v[t].depth = v[v[t].parent].depth+1;
                for(int x:v[t].children) q.push(x);
            }
            break;
        }
    }
    for(int i=0;i<n;i++){
        //node 0: parent = -1, depth = 0, root, [1, 4, 10]
        cout << "node " << v[i].node << ": parent = " << v[i].parent << ", depth = " << v[i].depth << ", ";
        if(v[i].depth==0) cout << "root";
        else if(v[i].children.empty()) cout << "leaf";
        else cout << "internal node";
        cout << ", [";
        if(!v[i].children.empty()){
            cout << v[i].children[0];
            for(int j=1;j<v[i].children.size();j++) cout << ", " << v[i].children[j];
        }
        cout << "]" << endl;
    }

    
    return 0;
}
