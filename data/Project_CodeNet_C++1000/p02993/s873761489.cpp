#include <iostream>
 #include <string>
 using std::cin;
 using std::cout;
 using std::endl;
 using std::string;

 int main(void){
 string s;


 cin >> s;


 bool isgood = true;
 if (s[0] == s[1]) isgood = false;
 if (s[1] == s[2]) isgood = false;
 if (s[2] == s[3]) isgood = false;


 if (isgood) {
 cout << "Good" << endl;

} else {
 cout << "Bad" << endl;
 }

 return 0;
 }