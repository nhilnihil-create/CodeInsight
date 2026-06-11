#include <bits/stdc++.h>
using namespace std;
//vector <long long> nCrModV;
long long before = 0;
long long ans = 0;
long long mod = (long long)pow(10,9)+7;
long long getPowerRemain(long long n, long long power, long long mod){
    #if 0
    cout << "n:" << n << " power:" << power << " mod:" << mod << endl;
    #endif
    //powを2進数で管理
    long long exp = 0;
    long long result = 1;
    long long nn = n;
    while(power>0){
        int tmp = (power&1);
        power>>=1;
        //cout << exp << endl;
        if(tmp!=0){
            if(exp>0){
                long long loopCnt = exp;
                while(loopCnt>0){
                    nn*=nn;
                    nn%=mod;
                    loopCnt--;
                }
                result*=nn;
                result%=mod;
                nn = n;
            }else{
                result*=n;
                result%=mod;
            }
        }
        exp++;
    }
    #if 0
    cout << "2進法出力：";
    for(int i = (binary.size()-1); i >=0; i--){
        cout << binary[i];
    }
    cout << endl;
    #endif
    #if 0
    for(int i = 0; i < powerVector.size(); i++){
        cout <<powerVector[i] << endl;
    }
    #endif
    #if 0
    for(int i = 0; i < resultVector.size(); i++){
        cout << resultVector[i] << endl;
    }
    #endif
    return result;

}
long long getInverseElement(long long base, long long mod){
    return getPowerRemain(base,mod -2,mod);
}
inline long long nCrMod(long long n, long long r, long long mod){
    long long ret = 1;
    long long inv = 1;
    if(r==1){
        ret = n;
    }else{
        for(long long i = 0; i < r; i++){
            ret*=(n-i);
            ret %= mod;
            inv*=getInverseElement(r-i,mod);
            inv %= mod;
        }
    }
    ret *= inv;
    ret %= mod;
    return ret;
}
int main(){
    #if 0
    return 0;
    #endif
    long long n,a,b;
    cin >> n >> a >> b;
    #if 0
    cout << getPowerRemain(2,6,mod) << endl;
    cout << pow(2,6) << endl;
    // for(int i = 0; i < 10; i++){
    //     cout << getPowerRemain(2,i,mod) << endl;
    // }
    return 0;
    #endif
    long long allpattern = getPowerRemain(2,n,mod);
    //cout << allpattern << endl;
    long long nCa = nCrMod(n,a,mod);
    //cout << nCa << endl;
    long long nCb = nCrMod(n,b,mod);
    //cout << nCb << endl;
    ans = allpattern - nCa - nCb - 1;
    while(ans<0){
        ans+=mod;
    }
    cout << ans << endl;
    return 0;
}