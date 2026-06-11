#include<iostream>
int main()
{
    int h, a, count = 0;
    std :: cin >> h >> a;
    for(int i = 0; ; i++)
    {
        if(h <= 0)
            break;
        h = h-a;
        count++;
    }
    std :: cout << count;
}