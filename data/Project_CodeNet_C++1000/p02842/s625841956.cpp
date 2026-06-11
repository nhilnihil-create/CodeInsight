#include <stdio.h>
#include <iostream>

//https://atcoder.jp/contests/sumitrust2019/tasks/sumitb2019_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    float N;
    std::cin >> N;

    int min = ((N - 10) * 0.926 - 1);
    int max = ((N + 10) * 0.926 + 1);

    for (int i = min; i < max; i++)
    {
        int nGuess = i * 1.08;
        if (nGuess == N)
        {
            std::cout << i << "\n";
            return 0;
        }
    }

    std::cout << ":(\n";
}
