//#include<iostream>
//#include<algorithm>
//#include<string>
//#include <cmath>
//#include <vector>
#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define REP(x,n) for(int x=0;x<n;x++)

//vector//
#define vei vector<int> 
#define velli vector<long long int> 
#define pb(x) push_back(x) // 末尾にxを加える
#define pb2 pop_back() // 末尾削除
#define all(x) (x).begin(),(x).end() //イテレーター
#define be(x) (x).begin()
//auto  auto begin = v.begin()とか

typedef pair<int,int> P;  //q(p.first,p.second)

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main (){
    int h, w ,k; cin >> h >> w >> k;
    vector<string> c(h);
    for(int i=0; i<h; i++){
        cin >> c[i];
    }

    int ans = 0;
    // bit全探索
    for(int bit_h=0; bit_h < (1<<h); bit_h++){
        for(int bit_w=0; bit_w < (1<<w); bit_w++){
            int kk=0;
            for(int i=0; i<h; i++){
                for(int j=0; j<w; j++){
                    if(!(bit_h & (1<<i)) && !(bit_w & (1<<j))){
                        if(c[i][j] == '#'){
                            kk++;
                        }
                    }
                }
            }
            if(kk==k) ans++;
        }
    }
    cout << ans;
}