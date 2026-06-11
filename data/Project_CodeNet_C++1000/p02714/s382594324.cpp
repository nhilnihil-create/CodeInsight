#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

#define int long long

// index l <= x <= r
int get_imos(vector<int> &v, int l, int r){
    return v[r+1]-v[l];
}

signed main(){
    int N;
    cin >> N;
    string S;
    cin >>S;

    string rgb = "RGB";
    // int s
    vector<int> is(N);
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            if(S[i] == rgb[j])
                is[i] = j;
        }
    }

    // 全ての文字が異なるものの総和
    int ad = 0;

    vector<vector<int>> imos(3, vector<int>(N+1, 0));
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            if(j == is[i]){
                imos[j][i+1] = imos[j][i] + 1;
            }else{
                imos[j][i+1] = imos[j][i];
            }
        }
    }

    for(int i=0;i<N-2;i++){
        for(int j=i+1;j<N-1;j++){
            if(is[i]!=is[j]){
                int last = 3-is[i]-is[j];
                ad += get_imos(imos[last], j+1, N-1);
            }
        }
    }

    // 全て異なり，文字の間が同じ距離もの
    int sd = 0;
    for(int d=0;2*d+3<=N;d++){
        for(int i=0;2*d+2+i<N;i++){
            int i1 = i;
            int i2 = i + d + 1;
            int i3 = i + 2*d+2;
            if(is[i1]!=is[i2] && is[i2]!=is[i3]&&is[i1]!=is[i3])sd++;
        }
    }

    cout << ad - sd <<endl;
}