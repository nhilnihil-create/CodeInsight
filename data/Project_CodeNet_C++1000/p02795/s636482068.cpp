#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
#include <chrono>
#include <random>
 
using namespace std;
     
    int main(){
      int H, W, N;
      cin >> H >> W >> N;
      int X = max(H, W);
      int b = 0, t = 0;
      while(b<N){
        b += X;
        t++;
      }
      cout << t << endl;
    }