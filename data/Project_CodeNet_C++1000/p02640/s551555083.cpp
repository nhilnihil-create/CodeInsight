#include <iostream>
#include <string>

using namespace std;

int main(){
int x,y;
int leg;
string s = "No";

cin >> x >> y;

for(int i = 0;i <= x;i++){
    leg = i*4 + (x-i)*2;
    if(leg == y){
	s = "Yes";
	break;
    }
}

cout << s << endl;

return 0;
}
