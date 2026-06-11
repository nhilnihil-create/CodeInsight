#include <bits/stdc++.h>
using namespace std;
int main(){
int red, green, blue,k;
cin >> red >> green >> blue >> k;
int count = 0;
while(red >= green){
	green = green * 2;
	count++;
	}
while(green >= blue){
	blue = blue * 2;
	count++;
}
if(count <= k){
cout << "Yes" << endl;
} else {
cout << "No" << endl;
}

}