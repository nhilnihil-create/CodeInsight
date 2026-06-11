#include<iostream>
#include<cstring>
using namespace std;
using ll = long long;

int main (){
    string S;
    cin >> S;
    int label;
    if(S == "MON"){label = 1;
    }else if(S == "TUE"){label = 2; 
    }else if(S == "WED"){label = 3;
    }else if(S == "THU"){label = 4;
    }else if(S == "FRI"){label = 5;
    }else if(S == "SAT"){label = 6;
    }else if(S == "SUN"){label = 0;
    }
    int ans = 7 - label;
    cout << ans << endl;
    return 0;
}
    