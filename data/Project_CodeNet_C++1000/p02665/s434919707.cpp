#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
const int MAXN = 1e5+1; int A[MAXN]; ll D[MAXN];

int main(int argc, const char * argv[]) {
    int N; cin >> N;
    for(int i = 0; i <= N; i++)
        cin >> A[i];
    if(N == 0){
      if(A[0] == 1)
        cout << 1 << endl;
      else
        cout << -1 << endl;
      return 0;
    }
    if(N > 0 && A[0] != 0){
        cout << -1 << endl;
        return 0;
    }
    D[N] = 0; ll sum = A[N];
    for(int i = N-1; i >= 1; i--){
        D[i] = D[i+1]+A[i+1];
        sum += A[i];
    }
    bool test = true;
    D[0] = 1; sum++;
    for(int i = 1; i <= N; i++){
        D[i] = min(2*D[i-1]-A[i], D[i]);
        if(D[i] < 0){
            cout << -1 << endl; 
          	return 0;
        }
        sum += D[i];
    }
    cout << sum << endl;
    return 0;
}
