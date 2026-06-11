#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    string X;
    int i;

    cin >> N;
    vector<int> t(N);
    vector<string> s(N);
    for(i = 0; i < N; i++) {
        cin >> s[i] >> t[i];
    }
    cin >> X;

    for(i = 0; i < N; i++) {
        if(s[i] == X) {
            i += 1;
            break;
        }
    }
    int sum = 0;
    for( ; i < N; i++) {
        sum += t[i];
    }

    cout << sum << endl;

    return 0;
}