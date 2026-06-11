#include <iostream>

using namespace std;

int main()
{
    string s[] = {"Sunny","Cloudy","Rainy"};
    string input;
    cin >> input;
    if(input == s[0]){
      cout << s[1] << endl;
    }else if( input== s[1]){
      cout << s[2] << endl;
    }else {
      cout << s[0] << endl;
    }
    return 0;
}
