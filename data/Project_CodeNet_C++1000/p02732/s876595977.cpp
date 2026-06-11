#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<cstddef>
#include<queue>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
    long long N, ans = 0;
    cin >> N;
    vector<long long> A(N), B(N);//B:書かれた整数ごとのボールの個数
    for(int i = 0; i < N; ++i){
        cin >> A.at(i);
        B.at(A.at(i) - 1)++;
    }
    for(int i = 0; i < N; ++i) ans += B.at(i)*(B.at(i) - 1)/2;//ボール選び出し総和
    for(int i = 0; i < N; ++i) cout << ans - B.at(A.at(i) - 1) + 1 <<endl;
    return 0;
}
