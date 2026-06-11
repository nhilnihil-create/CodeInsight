#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

namespace commit
{

long long
SolveSecondSum(const std::vector<int> &originalInputs)
{
    long long sum = 0;
    int increasingCount = 0;
    int decreasingCount = 0;
    for (std::size_t index = 1; index<originalInputs.size(); ++index)
    {
        if (originalInputs[index-1]<originalInputs[index]) ++increasingCount;
        else ++decreasingCount;
    }

    auto usingPtr = &originalInputs;
    std::vector<int> reversedInputs;
    auto decreasingPercentage = decreasingCount*100/(originalInputs.size()-1);
    if (decreasingPercentage>55)
    {
        reversedInputs = originalInputs;
        std::reverse(reversedInputs.begin(), reversedInputs.end());
        usingPtr = &reversedInputs;
    }

    const std::vector<int> &inputs = *usingPtr;

    //! M1: Max, M2: SecondMax.
    //! @brief Map of {M2, Count}.
    using SecondMaxCountMap = std::map<int, int>;
    //! @brief Map of {M1, Map of {M2, Count}}.
    std::map<int, SecondMaxCountMap> maxSortedLists;

    auto CountSecondMap = [](const SecondMaxCountMap &secondMap) -> int
    {
        return std::accumulate(secondMap.begin(), secondMap.end(),
            0,
            [](int count, const SecondMaxCountMap::value_type &pair) -> int
            {
                return count+pair.second;
            }
        );
    };

    auto min = inputs[0];

    for (std::size_t index=0; index<inputs.size(); ++index)
    {
        auto &input = inputs[index];

        if (index>0 && input<min)
        {
            auto &lastInput = inputs[index-1];
            maxSortedLists[lastInput].erase(0);
            maxSortedLists[lastInput][input] = 1;

            for (auto itM1 = maxSortedLists.begin(); itM1!=maxSortedLists.end(); ++itM1)
            {
                auto &secondMaxMap = itM1->second;
                for (auto itM2 = secondMaxMap.begin(); itM2!=secondMaxMap.end(); ++itM2)
                {
                    auto &secondMax = itM2->first;
                    auto &count = itM2->second;
                    sum += static_cast<long long>(secondMax)*count;
                }
            }
            min = input;
            maxSortedLists[input][0] = 1;
            continue;
        }

        auto lowerBound = maxSortedLists.lower_bound(input);
        if (lowerBound!=maxSortedLists.end())
        {
            for (auto itM1=lowerBound; itM1!=maxSortedLists.end(); ++itM1)
            {
                auto &secondMaxMap = itM1->second;
                auto m2LowerBound = secondMaxMap.lower_bound(input);
                int totalCount = 0;
                for (auto itM2=secondMaxMap.begin(); itM2!=m2LowerBound; ++itM2)
                {
                    totalCount += itM2->second;
                }
                secondMaxMap.erase(secondMaxMap.begin(), m2LowerBound);

                if (totalCount!=0)
                {
                    secondMaxMap[input] = totalCount;
                }

                for (auto itM2=secondMaxMap.begin(); itM2!=secondMaxMap.end(); ++itM2)
                {
                    auto &secondMax = itM2->first;
                    auto &count = itM2->second;
                    sum += static_cast<long long>(secondMax)*count;
                }
            }
        }

        SecondMaxCountMap updateSecondMaxCountMap;
        for (auto itM1=maxSortedLists.begin(); itM1!=lowerBound; ++itM1)
        {
            auto &max = itM1->first;
            auto &secondMaxMap = itM1->second;
            updateSecondMaxCountMap[max] = CountSecondMap(secondMaxMap);
        }

        maxSortedLists.erase(maxSortedLists.begin(), lowerBound);

        for (auto itM2 = updateSecondMaxCountMap.begin(); itM2!=updateSecondMaxCountMap.end(); ++itM2)
        {
            auto &newSecondMax = itM2->first;
            auto &count = itM2->second;
            if (newSecondMax==0) continue;
            maxSortedLists[input][newSecondMax] = count;
            sum += static_cast<long long>(newSecondMax)*count;
        }

        maxSortedLists[input][0] = 1;
    }

    return sum;
}

}

int
main()
{
    std::vector<int> inputs;

    std::size_t n = 0;
    std::cin >> n;

    inputs.resize(n);
    for (std::size_t i=0; i<n; ++i)
    {
        std::cin >> inputs[i];
    }

    auto answer = commit::SolveSecondSum(inputs);
    std::cout << answer << "\n";
    return 0;
}
