#include <bits/stdc++.h>

#define rep(X,N) for(ll X = 0LL; X < (N); X++)
#define PI (acos(-1.0))
#define MODN 1000000007
#define MODN2 998244353
#define ALL(V) (V).begin(),(V).end()
#define INT_MAX_HALF (INT_MAX / 2)
#define EPS (1e-10)

using namespace std;
typedef long long ll;

int main(){

    string s;
    cin >> s;

    int size = s.size();

    if(size == 1){
        cout << 1 << endl;
    }else if(size == 2){
        if(s[0] == s[1]){
            cout << 1 << endl;
        }else{
            cout << 2 << endl;
        }
    }else{

        string prevs = s.substr(0, 1);
        int count = 0;
        int i = 1;

        while(i < size){
            if(i == size - 2){
                if(prevs.size() == 1){
                    if(s[i - 1] != s[i] && s[i] != s[i + 1]){
                        count = count + 2;
                        break;
                    }else{
                        count++;
                        break;
                    }
                }else{
                    if(s[i] == s[i + 1]){
                        count++;
                        break;
                    }else{
                        count = count + 2;
                        break;
                    }
                }
            }else{

                for(int j = 1; i + j - 1 < size; j++){
                    string tmps = s.substr(i, j);

                    if(prevs != tmps){
                        count++;
                        prevs = tmps;

                        i += j;
                        break;
                    }
                }
            }
        }
        cout << count + 1 << endl;
    }

    return 0;
}
