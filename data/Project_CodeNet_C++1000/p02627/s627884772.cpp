#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>

using namespace std;

int main(int argc, const char * argv[]) {
    
    // input from txt
    //std::ifstream in("test.txt");
    //std::cin.rdbuf(in.rdbuf());
    
    char c;
    cin >> c;
    if(isupper(c)){
        cout << "A" << endl;
    }else{
        cout << "a" << endl;
    }
    
    return 0;
}
