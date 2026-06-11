#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    cin >> str;
    if(str == "SSS"){
        cout << 0 << endl;
    }
    else if(str == "RRR"){
        cout << 3 << endl;
    }
    else if(str == "RRS" || str == "SRR"){
        cout << 2 << endl;
    }
    else if(str == "RSS" || str == "SRS" || str == "SSR"|| str == "RSR"){
        cout << 1 << endl;
    }
}
