#include <iostream>

using namespace std;

int main()
{
    double d, t, s;
    while(cin >> d >> t >> s){
        if(d/s>t)cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}
