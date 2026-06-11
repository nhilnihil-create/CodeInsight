#include <bits/stdc++.h>
#define INF 1e9
using namespace std;
using ll = long long;

int main(void) {
    string N;
    cin >> N;
    for (int i = 0; i < 3; i++)
    {
        if(N[i] == '7'){
            cout << "Yes"<<endl;
            return 0;
        }
    }

    cout <<"No"<<endl;
    
    return 0;
}
