#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;

main(){
    int n;cin>>n;
    set<string> s;
    string temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        s.insert(temp);
    }
    cout<<s.size();
}