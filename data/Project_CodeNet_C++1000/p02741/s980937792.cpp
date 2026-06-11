/**************************
*                         *
*  Nothing Is Impossible  *
*                         *
**************************/
#include <algorithm>
#include <pthread.h>
#include <iostream>
#include <fstream>
#include <ctype.h>
#include <string>
#include <vector>
#include <thread>
#include <math.h>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#define GetRand(Min, Max) ((rand()%(int)(((Max) + 1)-(Min))) + (Min))
#define Rep(i, min, max) for(int64_t i = min; i < max; ++i)
#define PB push_back
#define MP make_pair
typedef long long ll;
typedef long double ld;
using namespace std;

int arr[] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};

int main()
{
  ios::sync_with_stdio(NULL);
  cin.tie(NULL); cout.tie(NULL);
  int n;  cin >> n;
  cout << arr[n-1] << endl; 
  return 0;
}
