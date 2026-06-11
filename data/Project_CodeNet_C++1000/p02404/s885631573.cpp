#include <string>
#include <iostream>
using namespace std;

int main()
{
    int h, w;
    
    while(cin >> h >> w && h && w) {
        string top(w, '#');
        string middle(w,'.');
        middle[0] = '#'; middle.back() = '#';
        
        cout << top << '\n';
        while(h-- > 2) cout << middle << '\n';
        cout << top << '\n' << endl;
    }
    
    return 0;
}
