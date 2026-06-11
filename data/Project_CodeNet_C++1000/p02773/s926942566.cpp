#include<bits/stdc++.h>
using namespace std;

int main(){
    int T,i,j,n;
    map<string,int> mp;

    cin>>n;
    string s;
    string a[n+1];
    int p=1;
    int cnt[n+1];
    memset(cnt,0,sizeof(cnt));

    for(i=0;i<n;i++){
        cin>>s;
        if(mp.find(s)==mp.end()){
            mp[s]=p;
            a[p]=s;
            cnt[p]=1;
            p++;
        }
        else{
            cnt[mp[s]]++;
        }
    }

    set<string> st;
    int mx=0;
    for(i=1;i<p;i++){
        if(cnt[i]>mx) mx=cnt[i];
    }
    for(i=1;i<p;i++){
        if(cnt[i]==mx){
            st.insert(a[i]);
        }
    }
    for(set<string>:: iterator itr=st.begin();itr!=st.end();itr++){
        cout<<*itr<<endl;
    }



return 0;
}
