#include <iostream>
#include <string>
using namespace std;

int main()
{
    while (true) {
        int h, w;
        cin >> h >> w;
        
        if (!h && !w) break;
        
        string s(w, '#');
        
        for (int i = 0; i < h; i++)
            cout << s << "\n";
            
        cout << "\n";
    }
    
}