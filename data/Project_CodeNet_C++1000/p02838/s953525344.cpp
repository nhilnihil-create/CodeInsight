#include <bits/stdc++.h>
using namespace std;
#define DEBUG false
int main(){
    unsigned long long n;
    cin >> n;
    unsigned long long mod = pow(10,9)+7;
    vector <unsigned long long> a(n);
    unsigned long long maxA = 0;
    unsigned long long bit1Sum = 0;
    unsigned long long bit2Sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        maxA = max(a[i],maxA);
        if((a[i]&0x01)==0x01)bit1Sum++;
        if((a[i]&0x02)==0x02)bit2Sum++;
        //cout << bitset<60>(a[i])<<endl;
    }
    //cout << bit1Sum << " " << bit2Sum << endl;
    //cout << bitset<60>(maxA) << endl;
    //cout << bitset<60>(9375105820) << endl;
    if(DEBUG){
        long long ans = 0;
        vector <vector<int>> vv(n);
        for(int i = 0; i < n-1; i++){
            vv[i]=vector<int>(n,0);
            for(int j = i+1; j < n; j++){
                vv[i][j]++;
                ans+=a[i]^a[j];
                ans%=mod;
            }
        }
        cout << ans << endl;
    }
    vector <vector<unsigned long long>> bitnum;
    for(int i = 0; i < 62; i++){
        unsigned long long mask = (unsigned long long)0x01 << (unsigned long long)i;
        //cout << i << " " << mask << " " << maxA << endl;
        if(mask>maxA)break;
        bitnum.push_back(vector<unsigned long long>(n,0));
        for(unsigned long long j = 0; j < n; j++){
            if((a[j]&mask)==mask){
                if(j==0){
                    bitnum[i][j]=1;
                }else{
                    bitnum[i][j]=bitnum[i][j-1]+1;
                }
            }else{
                if(j==0){
                    bitnum[i][j]=0;
                }else{
                    bitnum[i][j]=bitnum[i][j-1];
                }
            }
        }
    }
    vector <unsigned long long> xorSum(bitnum.size(),0);
    for(unsigned long long i = 0; i < bitnum.size(); i++){
        for(unsigned long long j = 0; j < n-1; j++){
            //右辺の1の数を数える。
            unsigned long long num = bitnum[i][n-1];
            num -= bitnum[i][j];
            unsigned long long currentBit;
            if(j==0){
                currentBit = bitnum[i][j];
            }else{
                currentBit = bitnum[i][j]-bitnum[i][j-1];
            }
            if(currentBit==0){
                //左辺が0の時は右辺の1の数の総和がxorの総和
                xorSum[i]+=num;
            }else{
                unsigned long long maxNum = n-(j+1);
                xorSum[i]+=(maxNum-num);
            }
        }
    }
    // for(unsigned long long i = 0; i < bitnum.size(); i++){
    //     if(i%5==0)cout << endl;
    //     cout << bitnum[i].back() << " ";
    // }
    // cout << endl;

    unsigned long long ans = 0;
    for(unsigned long long i = 0; i < xorSum.size(); i++){
        if(xorSum[i]==0)continue;
        unsigned long long exp = i;
        unsigned long long tmp = xorSum[i];
        while(exp>0){
            tmp*=2;
            tmp%=mod;
            exp--;
        }
        ans+=tmp;
        ans%=mod;
    }
    cout << ans << endl;
    return 0;
}