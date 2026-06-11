#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool visted[200010];
vector<int> vt[200010];
vector<int> v[200010];
ll n , m ;
ll numberOfConnectedComponent;
void dfs(int index) {
    if(!visted[index]) {
        visted[index] = true;
        vt[numberOfConnectedComponent].push_back(index);
        for(int i=0;i<v[index].size(); i++) {
            dfs(v[index][i]);
        }
    } else {
        return;
    }
}
int main() {
    cin>>n>>m;

    for(int i=0;i<m;i++) {
        int c1 , c2;
        cin>>c1>>c2;
        v[c1-1].push_back(c2-1);
        v[c2-1].push_back(c1-1);
    }
    if(m == 0) {
        cout<<1<<endl;
        return 0 ;
    }
    int maxx = INT_MIN;
    for(int i=0; i<n; i++) {
        if(!visted[i]) {
            dfs(i);
            int tempSize = vt[numberOfConnectedComponent].size();
            maxx = max(maxx, tempSize);
            numberOfConnectedComponent++;
        }
    }
    /*bool haveSinglGrpupe = false;
    for(int i=0;i<n;i++) {
        if(v[i].size() == 0) {
            haveSinglGrpupe = true;
            break;
        }
    }*/
    /*if(haveSinglGrpupe) {
        cout<<maxx-1<<endl;
    }
    else {
        cout<<maxx;
    }*/
    cout<<maxx<<endl;
}
