#include <bits/stdc++.h>
using namespace std;
#define int long long
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

signed main(){
    int K;cin>>K;

    vector<string> lunlun;
    for(int i=1;i<10;i++){
        lunlun.push_back(to_string(i));
//        cout<<lunlun.at(i-1)<<endl;;
    }

    vec_int keta_num;
    keta_num.push_back(-1);
    keta_num.push_back(8); //1の位はlunlun.at(8)まで
    int index=2; // これは10の位の数から始めるということ

    int bangou=9;
    while(bangou<pow(10,5)+1){
        for(int i=keta_num.at(index-2)+1;i<=keta_num.at(index-1);i++){
            string prev = lunlun.at(i);
 //           cout<<prev<<endl;
            int length = prev.size();
            int last_num = charToInt(prev.at(length-1));
            for(int j=0;j<10;j++){
                if(j==last_num){
                    if(j==0){
                        lunlun.push_back(prev+"0");
                        lunlun.push_back(prev+"1");
                        bangou+=2;
                    }else if(j==9){
                        lunlun.push_back(prev+"8");
                        lunlun.push_back(prev+"9");
                        bangou+=2;
                    }else{
                        for(int k = -1;k<2;k++){
                        lunlun.push_back(prev+to_string(j+k));
                        }
                        bangou+=3;
                    }
                    if(bangou>pow(10,5))goto OUT;
                    break;
                }
            }
            if(bangou>pow(10,5))break;
        }
        //前の桁が終わったときの処理
        index++;
        keta_num.push_back(lunlun.size()-1);
    }
    OUT:
    cout<<lunlun.at(K-1)<<endl;


    return 0;
}