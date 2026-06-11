#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

//https://atcoder.jp/contests/abc160/tasks/abc160_c

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int fullDist, houseNum;
    std::cin >> fullDist >> houseNum;

    int maxDiff = 0;
    int lastDist = 0;

    int firstDiff = -1;
    for (int i = 0; i < houseNum; i++)
    {
        int houseDist;
        std::cin >> houseDist;
        int newDiff = houseDist - lastDist;

        if (firstDiff == -1)
        {
            firstDiff = newDiff;
        }

        maxDiff = std::max(newDiff, maxDiff);
        lastDist = houseDist;
    }

    int newDiff = (fullDist - lastDist) + firstDiff;
    maxDiff = std::max(newDiff, maxDiff);

    std::cout << (fullDist - maxDiff) << "\n";
}
