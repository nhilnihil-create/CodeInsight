#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<set<pair<int,int> > >tree(n);
    int a[n-1];
    int b[n-1];
    for(int i=0;i<n-1;i++){
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        tree[a[i]].insert(make_pair(b[i],i));
    }
    int maxx = 0;
    vector<int>colors(n);
    queue<pair<int,int> >que;
    que.push(make_pair(0,0));
    while(!que.empty()){
        int next = que.front().first;
        int hen = que.front().second;
        que.pop();
        if(hen > maxx)maxx = hen;
        int tmp=0;
        for(auto j: tree[next]){
            tmp++;
            if(tmp == hen)tmp++;

            que.push(make_pair(j.first,tmp));
            colors[j.second] = tmp;
        }
    }

    cout << maxx << endl;
    for(int i=0;i<n-1;i++)cout<<colors[i] << endl;
    
    
}
