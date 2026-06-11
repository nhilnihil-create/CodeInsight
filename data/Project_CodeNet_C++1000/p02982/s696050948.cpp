#include<iostream>
#include<iomanip>
#include<string>
#include<algorithm>
#include<vector>
#include<utility>
#include<tuple>
#include<map>
#include<queue>
#include<stack>
#include<deque>
#include<bitset>
#include<math.h>
using namespace std;
using ll = int64_t;
using Graph = vector<vector<int> >;
const ll M = 1000000007;

int main(){
    int n,d;
    cin >> n >> d;
    int x[n][d];
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin >> x[i][j];
        }
    }

    int c=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            int tmp=0;
            for(int k=0;k<d;k++){
                tmp += (int)pow((x[i][k]-x[j][k]),2);
            }
            if((int)pow(tmp,0.5)==pow(tmp,0.5)) c++;
        }
    }
    cout << c << endl;
}