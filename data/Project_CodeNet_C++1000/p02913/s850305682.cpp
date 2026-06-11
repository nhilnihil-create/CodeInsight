#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    string s;cin>>s;
    int r=n/2,l=0,ans=0;
    while(r-l>1){
        int m=(r+l)/2,length=0;
        map<string,pair<int,int>>a;
        for(int j=0;j<n-m+1;j++){
            string t=s.substr(j,m);
            if(a[t].second>0){
                if(a[t].first+m<=j){length=m;break;}
                a[t].second++;
            }
            else{
                a[t].first=j;
                a[t].second++;
            }
        }
        if(length>0){
            l=m;
            ans=length;
        }
        else{r=m;}
    }
    map<string,pair<int,int>>a;
    for(int j=0;j<n-r+1;j++){
        string t=s.substr(j,r);
        if(a[t].second>0){
            if(a[t].first+r<=j){ans=r;break;}
            a[t].second++;
        }
        else{
            a[t].first=j;
            a[t].second++;
        }
    }
    cout<<ans<<endl;
}
