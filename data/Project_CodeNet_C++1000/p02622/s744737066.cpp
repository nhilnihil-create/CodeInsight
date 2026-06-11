#include <iostream>

using namespace std;

int main()
{
    string S , T ;
    int cnt = 0 ;
    cin >> S >> T ;
    int sz = S.size();
    for(int i = 0 ; i < sz ; ++i)
    {
        if(S[i] != T[i])
            cnt++;
    }
    cout << cnt ;
    return 0;
}
