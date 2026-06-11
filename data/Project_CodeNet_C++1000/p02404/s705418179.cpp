#include <iostream>

using namespace std;

void print_char_line(const int n, const char edge, const char inside)
{
    cout << edge;
    for (int i = 0; i < n - 2; ++i)
    {
        cout << inside;
    }
    cout << edge << endl;
}

void print_frame(const int height, const int width)
{
    print_char_line(width, '#', '#');
    for (int i = 0; i < height - 2; ++i)
    {
        print_char_line(width, '#', '.');
    }
    print_char_line(width, '#', '#');
}

int main()
{
    int a, b;
    while (cin >> a >> b, a != 0 || b != 0)
    {
        print_frame(a, b);
        cout << endl;
    }
    return 0;
}