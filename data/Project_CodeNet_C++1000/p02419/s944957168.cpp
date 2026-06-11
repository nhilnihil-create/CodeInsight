#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    string W, T;
    int cnt {0};
    cin >> W ;

    while(true){
        cin >> T;
        if( T == "END_OF_TEXT")
            break;
        for(auto&& c: T){
            c = tolower(c);
        }
        if( W == T){
            cnt++;
        }
    }
    cout << cnt << endl;

    return 0;
}
