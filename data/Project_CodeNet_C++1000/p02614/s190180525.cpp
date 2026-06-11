#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
    int h,w,k,a[20]={};
    int ans=0,sum1=0;
    string s[10];
    cin>>h>>w>>k;
    for(int i=0;i<h;i++){
        cin>>s[i];
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(s[i][j]=='#'){
                a[i]++;
                a[j+h]++;
                sum1++;
            }
        }
    }
    for(int bit=0;bit<(1<<w+h);bit++){
        int c1=0,c2=0,sum=sum1,b[10],d[10];
        for(int i=0;i<w+h;i++){
            if(bit & (1<<i)){
                if(i>=h){
                    d[c2]=i;
                    c2++;
                }
                else{
                    b[c1]=i;
                    c1++;
                }
            }
        }
        for(int i=0;i<c1;i++){
            sum-=a[b[i]];
        }
        for(int i=0;i<c2;i++){
            sum-=a[d[i]];
        }
        for(int i=0;i<c1;i++){
            for(int j=0;j<c2;j++){
                if(s[b[i]][d[j]-h]=='#'){
                    sum++;
                }
            }
        }
        if(sum==k)
            ans++;
    }
    cout<<ans<<endl;
    return(0);
}