#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int P;
    int Q;
    int R;
    cin >> P;
    cin>>Q;
    cin>>R;
    
    cout<<P+Q+R - std::max({P, Q, R});

	return 0;
}