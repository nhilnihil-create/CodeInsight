#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>

using namespace std;
const double PI (acos(-1));


int main()
{
 int H, A;
 cin >> H >> A;

int num =0;
 while(H > 0 )
 {
   H -= A;
   num++;
 }

cout << num;

}
