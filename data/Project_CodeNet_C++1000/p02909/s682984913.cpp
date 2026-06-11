#include<iostream>
using namespace std;

int main(void)
{
    char s[7];
    cin >> s;
    if(s[0] == 'S'){
        cout << "Cloudy" << endl;
    }else if(s[0]=='C'){
        cout << "Rainy" << endl;
    }else
    {
        cout << "Sunny" << endl;
    }

    return 0;
}
