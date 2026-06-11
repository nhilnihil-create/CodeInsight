#include <iostream>
#include <string>
using namespace std;
int v2(int x){
    if(x==0) return 0;
    return x/2+v2(x/2);
}
bool div2(int n,int k){
    if(n==0 && k==0) return false;
    return (v2(n)-v2(k)-v2(n-k))>0;
}
int main(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    int dig[n];
    for(int i=0;i<n;i++){
        if(a[i]=='1'){
            dig[i] = 1;
        }
        else if(a[i]=='2'){
            dig[i] = 2;
        }
        else{
            dig[i] = 3;
        }
    }
    int mod2 = 0;
    for(int i=0;i<n;i++){
        if(!div2(n-1,i)){
            mod2+=dig[i];
            mod2%=2;
        }
    }
    if(mod2%2){
        cout << 1 << endl;
        return 0;
    }
    //differentiate between 0 and 2??
    int dig2[n-1];
    bool zero = false;
    for(int i=0;i<n-1;i++){
        dig2[i] = abs(dig[i]-dig[i+1]);
        if(dig2[i]%2) zero = true;
    }
    int mod4 = 0;
    for(int i=0;i<n-1;i++){
        if(!div2(n-2,i)){
            mod4+=dig2[i];
            mod4%=4;
        }
    }
    if(mod4%4==2 && !zero){
        cout << 2 << endl;
    }
    else{
        cout << 0 << endl;
    }

    return 0;

}

