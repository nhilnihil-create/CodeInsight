#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;

int main() {
    int N,M; cin>>N>>M;
    vector<int> wa(N,0);
    int ac=0;
    int pena=0;
    for (int i = 0; i < M; i++){
        int p;cin>>p;p--;
        string s;cin>>s;
        if(wa[p]>=0){
            if(s=="AC"){
                ac++;
                pena+=wa[p];
                wa[p]=-1;
            }else wa[p]++;
        }
    }
    cout<<ac<<" "<<pena<<endl;
}