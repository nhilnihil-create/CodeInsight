#include <iostream>
#include <string>

int main(void)
{
    using namespace std;
    
    string W, T;
    int i, cnt;

    cin >> W;
    for (i = 0; i < W.size(); ++i) {
        if (isupper(W[i])) {
            W[i] = tolower(W[i]);
        }
    }

    while (cin >> T) {
        if (T == "END_OF_TEXT") break;
        
        for (i = 0; i < T.size(); ++i) {
            if (isupper(T[i])) {
                T[i] = tolower(T[i]);
            }
        }
        
        if (T == W) {
            cnt++;
        }
    }
    cout << cnt << endl;
    
    return 0;
}