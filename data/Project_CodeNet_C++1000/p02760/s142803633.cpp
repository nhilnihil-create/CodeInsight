#include<iostream>
using namespace std;

int main(){
int a[100][100], b[100], n;
for(int i = 1;i <= 3;i++){
for(int j = 1;j <= 3;j++){
cin >> a[i][j];
}
}
cin >> n;
for(int k = 0;k < n;k++){
cin >> b[k];
}
for(int k = 0;k < n;k++){
for(int i = 1;i < 4;i++){
for(int j = 1;j < 4;j++){
if(a[i][j] == b[k]){
a[i][j] = 1000;
}
}
}
}
if(a[1][1] == 1000 && a[2][1] == 1000 && a[3][1] == 1000){
cout << "Yes";
}
else if(a[1][2] == 1000 &&  a[2][2] == 1000 && a[3][2] == 1000){
cout << "Yes";
}
else if(a[1][3] == 1000 && a[2][3] == 1000 && a[3][3] == 1000){
cout << "Yes";
}
else if(a[1][1] == 1000 && a[1][2] == 1000 && a[1][3] == 1000){
cout << "Yes";
}
else if(a[2][1] == 1000 && a[2][2] == 1000 && a[2][3] == 1000){
cout << "Yes";
}
else if(a[3][1] == 1000 && a[3][2] == 1000 && a[3][3] == 1000){
cout << "Yes";
}
else if(a[1][1] == 1000 && a[2][2] == 1000 && a[3][3] == 1000){
cout << "Yes";
}
else if(a[3][1] == 1000 && a[2][2] == 1000 && a[1][3] == 1000){
cout << "Yes";
}
else{
cout << "No";
}
}