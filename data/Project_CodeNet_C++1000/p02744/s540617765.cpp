#include <iostream>
#include <cmath>
using namespace std;

int n;

void task(string s, int mx);

int main(void)
{
    //const double PI=3.141592653589793238;

    cin >> n;
    task("a", 0);
    return 0;
}

void task(string s, int mx)
{
    if(s.size() == n)
    {
        cout << s << endl;
        return;
    }

    for(int i=0; i<=mx+1; ++i){
        task(s + char('a'+i), max(mx, i));
    }

    
}