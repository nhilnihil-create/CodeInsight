#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

int ans[500][500];
void separate(int s, int g, int r){
    if(g-s<=1){
        return;
    }
    int mid=(s+g)/2;
    for(int i=s; i<mid; i++){
        for(int j=mid; j<g; j++){
            //cout << i << ' ' << j << ' ' << r << endl;
            ans[i][j]=r;
        }
    }
    separate(s, mid, r+1);
    separate(mid, g, r+1);
}

int main(){
    int N;
    cin >> N;

    separate(0,N,1);

    for(int i=0; i<N; i++){
        for(int j=i+1; j<N; j++){
            cout << ans[i][j];
            if(j<N-1){
                cout << ' ';
            }
        }
        cout << '\n';
    }
}