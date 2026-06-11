#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <cstdlib>
using namespace std;
int main()
{
    char input[8];
    vector<long> stack;
    while(cin >> input)
    {
        if(isdigit(*input))
        {
            long t = atol(input);
           stack.push_back(t);
        }
        else
        {
            long b = stack.back();
            stack.pop_back();
            long a = stack.back();
            stack.pop_back();
            switch(*input)
            {
            case '+':
                a += b;
                break;
            case '-':
                a -= b;
                break;
            case '*':
                a *= b;
                break;
            case '/':
                a /= b;
                break;
            default:
                break;
            }
            stack.push_back(a);
        }
    }
    cout << stack[0] << endl;
}