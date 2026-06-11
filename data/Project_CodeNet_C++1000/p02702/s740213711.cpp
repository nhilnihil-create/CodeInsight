#include <iostream>
using namespace std;
string s;
int a[2019],A,b[2019],ans;
int main(void){
    cin>>s;
    for(int i=0;i<s.size();i++){
        //cout<<i<<"I"<<endl;
        a[0]++;
        A=s[i]-'0';
        for(int j=0;j<2019;j++){
            if(a[j]>0){
                //cout<<j<<" "<<(j*10+A)<<" "<<ans<<endl;
                b[(j*10+A)%2019]+=a[j];
            }
        }
        for(int j=0;j<2019;j++){
            a[j]=b[j];
            b[j]=0;
        }
        ans+=a[0];
    }
    cout<<ans<<endl;
}
