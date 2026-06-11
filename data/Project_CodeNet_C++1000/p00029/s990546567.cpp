#include <iostream>
#include <map>
#include <stdio.h>

int main(void)
{
	std::map<std::string,int> words;
	char word[33];
	while(~scanf("%s",word))
	{
		if(words.find(word)==words.end())
			words[word]=0;
		words[word]++;
	}

	int max=0;
	std::string mode,longest;
	for(std::map<std::string,int>::iterator it = words.begin(); it != words.end(); it++)
	{
		if(it->second > max)
		{
			max = it->second;
			mode = it->first;
		}
		if(it->first.size() > longest.size())
		{
			longest = it->first;
		}
	}
	std::cout << mode << " " << longest << std::endl;
	return 0;
}