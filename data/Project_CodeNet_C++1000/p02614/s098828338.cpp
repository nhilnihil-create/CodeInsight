//@author :  |< U $ |-|
#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#define TakeInput freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
using namespace std;



int main(){
    
    #ifndef ONLINE_JUDGE
    TakeInput
    #endif
    
    int i,j,m,n,k,r,c;
    cin>>n>>m>>k;

    string a[n];
    for(i=0;i<n;i++){
        cin>>a[i];
    }
    int ans=0;
    for(i=0;i<(1<<n);i++){
        for(j=0;j<(1<<m);j++){
            int count=0;
            for(r=0;r<n;r++){
                for(c=0;c<m;c++){
                    // cout<<1<<endl;
                    if((((i>>r)&1)==0) && (((j>>c)&1)==0) && a[r][c] == '#'){
                        count++;
                    }
                }
            }
            // cout<<count<<endl;
            if(count==k)ans++;
        }
    }

    cout<<ans<<endl;
    

}
 
 
 