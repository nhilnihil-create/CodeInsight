#include <string>
#include <iostream>
using namespace std;

int main()
{
    int h, w;
    string line(301, '#');
    
    for(int i=0; i<301; ++i) line[i] = (i%2) ? '.' : '#';
    
    while(cin >> h >> w && h && w) {
        for(int i=0; i<h; ++i)
			cout << line.substr(i%2, w) << '\n';
        cout << endl;
        
    }
    
    return 0;
}

