#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string a, b;

    cin >> n;
    
    int pa = 0, pb = 0;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if (a > b) pa += 3;
        else if (a < b) pb += 3;
        else pa++, pb++;
    }
    cout << pa << " " << pb << endl;

    return 0;
}