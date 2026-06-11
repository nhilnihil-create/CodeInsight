#include<bits/stdc++.h>
using namespace std;

//フラグの立て方は、ループでbit<(1<<i)
//フラグが立っているかどうかは、bit&1<<n

int main(){
    //人数
    int n; cin>>n;
    //誰の何個めの証言か、名宛人とその内容
    int x[n][n],y[n][n];
    //各々の証言数
    int a[n];
    
    for(int i=0;i<n;i++){
        cin>>a[i];
        for(int j=0;j<a[i];j++){
            cin>>x[i][j]>>y[i][j];
        }
    }

    int ans=0;
    
    for(int bit=0;bit<(1<<n);bit++){
        bool can=true;
        for(int j=0;j<n;j++){
            if(!(bit&(1<<j))) continue;

            for(int k=0;k<a[j];k++){
                //名宛人は1からｎ、bitは0からn-1なので名宛人にー1する
                if(!(bit&(1<<(x[j][k]-1))) && y[j][k]) can=false;
                else if(bit&(1<<(x[j][k]-1)) && !(y[j][k])) can=false;
            }
        }

        if(can){
            int count=0;
            for(int i=0;i<n;i++){
                if(bit&(1<<i)) count++;
            }

            ans=max(ans,count);
        }

    }

    cout<<ans<<endl;
}