#include<iostream>
#include<iomanip>
using namespace std;

#define PI 3.14159265358979323

int main(){
   double r;
   cin >> r;
   
   cout << fixed << setprecision(5) << PI * r * r << " " << 2 * PI * r << endl;
    
}