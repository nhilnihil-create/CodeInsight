#include <iostream>
#include <string>

char Compare_Func(const char arg_a);

const int L_CHAR_MIN = 0x41;	// A
const int L_CHAR_MAX = 0x5a;	// Z
const int S_CHAR_MIN = 0x61;	// a
const int S_CHAR_MAX = 0x7a;	// z

int main()
{
	char Result = NULL;
	char Char_Temp = NULL;
	std::string buf;
	std::cin >> buf;
	if (!buf.empty())
	{
		Char_Temp = buf[0];
	}
	Result = Compare_Func(Char_Temp);
    std::cout << Result <<std::endl;
}


char Compare_Func(const char arg_a)
{
	char temp = NULL;
	if (((L_CHAR_MIN <= arg_a) && (L_CHAR_MAX >= arg_a)) || ((S_CHAR_MIN <= arg_a) && (S_CHAR_MAX >= arg_a)))
	{
		if ((L_CHAR_MIN <= arg_a) && (L_CHAR_MAX >= arg_a))
		{
			temp = 'A';
			return temp;
		}
		if ((S_CHAR_MIN <= arg_a) && (S_CHAR_MAX >= arg_a))
		{
			temp = 'a';
			return temp;
		}
	}
	return temp;
}