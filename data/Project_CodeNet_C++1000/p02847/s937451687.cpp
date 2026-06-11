#include <iostream>
#include <string>
using namespace std;
int main(){
     string S;
     int Day=0;
     cin >> S;
     if (S=="SUN")Day=7;
     if (S=="MON")Day=6;
     if (S=="TUE")Day=5;
     if (S=="WED")Day=4;
     if (S=="FRI")Day=2;
     if (S=="THU")Day=3;
     if (S=="SAT")Day=1;
     cout << Day <<endl;
}
