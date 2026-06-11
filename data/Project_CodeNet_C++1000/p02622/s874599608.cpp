#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int limit = 2*(1000000);
    char str1[limit];
    cin >> str1;
    char str2[limit];
    cin >> str2;
    int answer = 0;
    int size_ = strlen(str1);
    for (int i = 0; i < size_; i++)
    {
        if (str1[i] != str2[i])
        {
            answer++;
        }
        else
       {
            continue;
       }
    }
    cout << answer << endl;
    return 0;
}