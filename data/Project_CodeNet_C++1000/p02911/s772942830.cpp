#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int N, K, Q;    cin >> N >> K >> Q;
    vector<int> v(N,0);
    for(int i=0; i<Q; i++){
        int A;  cin >> A;
        v[A-1]++;
    }
    for(int i=0; i<N;i++){
        if(K-Q+v[i] > 0)    cout << "Yes" << '\n';
        else    cout << "No" << '\n';
    }
    return 0;
}