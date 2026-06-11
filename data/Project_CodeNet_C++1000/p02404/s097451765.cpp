#include <iostream>
#include <string>
using namespace std;

int main()
{
    while (true) {
        int h, w;
        cin >> h >> w;
        
        if (!h && !w) break;
        
        string s1(w, '#');
        
        string s2(w, '.');
        s2[0] = '#';
        s2[s2.size() - 1] = '#';
        
        cout << s1 << "\n";
        if (h > 2)
            for (int i = 1; i < h - 1; i++)
                cout << s2 << "\n";
        cout << s1 << "\n";
            
        cout << "\n";
    }
}