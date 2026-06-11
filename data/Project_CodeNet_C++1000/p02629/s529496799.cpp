#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


long long mypow(long long x, long long y);
    //////////////////////////////////////////
    //    整数用のpow
    //    in   : 整数, 整数
    //    out  : 整数 
    //    ver  : 1.0
    //    概要 : 正の整数での使用のみを想定
    //    include: NA
    //////////////////////////////////////////


int main(){
    long long K;
    long long tmp = 26;
    long long keta = 1;
    int moji;
    std::cin >> K;

    //最大桁数を探る
    while(1){
        if(tmp >= K){
            break;
        }else{
            keta++;
            tmp = tmp + mypow(26, keta);
        }

    }

    vector<char> ans(keta);

    tmp = K;
    for(int i = 1; i < keta; i++){
        tmp = tmp - mypow(26, i);
    }

    double dtmp = (double)tmp - 1.0;
    // std::cout << tmp << "\n";
    for(long long i = keta - 1; i >= 0; i--){
        //97がa
        //各桁数の文字を特定していく
        // std::cout << dtmp << "\n";
        if(i != 0){
            moji = (int)round(floor(dtmp/(double)mypow(26, i))) + 97;
            // std::cout << moji << " ";

            dtmp = dtmp - (double)(moji - 97) * (double)mypow(26, i);
            ans[keta - 1 - i] = moji;
        }else{
            ans[keta - 1] = (int)dtmp + 97;
            // std::cout << ans[keta -1] << "\n";
        }
    }

    for(int i = 0; i < ans.size(); i++){
        std::cout << ans[i];
    }

}

long long mypow(long long x, long long y){
    long long ans = 1;
    for(long long i = 0; i < y; i++){
        ans = ans * x;
    }
    return ans;
}