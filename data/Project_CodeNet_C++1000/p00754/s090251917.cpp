#include <stdio.h>
#include <string.h>

#define MAX_STR_LEN 102

int CheckBracket(char *bracketStr, int *bracketStrIdx, char inputStr);

int main()
{
	char inputStr[MAX_STR_LEN]   = {'\0'};		// Array for input string
	int  inputStrLen = 0;						// Length of input string
	char bracketStr[MAX_STR_LEN] = {'\0'};		// Array for keep left-bracket
	int  bracketStrIdx = 0;						// Index of "bracketStr"
	char compareBracket = '\0';					// Valiable of select bracket to compare
	int  falseFlg = 0;							// Flag of sign false
	int  i = 0;									// Loop valiable
	
	do{
		// Initialize parameter.
		for(i = 0; i < MAX_STR_LEN; i++)
		{
			inputStr[i]    = '\0';
			bracketStr[i]  = '\0';
		}
		bracketStrIdx  = 0;
		compareBracket = '\0';
		falseFlg       = 0;
		
		// Input string.
//		printf("Input string >> ");
		fgets(inputStr, MAX_STR_LEN, stdin);
//		puts(inputStr);
		inputStrLen = strlen(inputStr);
		
		// If input string is '.' only, end.
		if('.' == inputStr[0])
		{
			break;
		}
		
		// Check to match bracket.
		for(i = 0; i < inputStrLen; i++)
		{
			switch(inputStr[i])
			{
			// If inputStr[i] is left-bracket, connect to "bracketStr".
			case '(':
			case '[':
				bracketStr[bracketStrIdx] = inputStr[i];
				bracketStrIdx++;
				break;
				
			// If inputStr[i] is right-bracket, Check to match bracket.
			case ')':
			case ']':
				falseFlg = CheckBracket(bracketStr, &bracketStrIdx, inputStr[i]);
				break;
				
			case '.':
				// If bracketStr is not empty, falseFlg is 1.
				if(0 != bracketStrIdx)
				{
					falseFlg = 1;
				}
				break;
			default:
				break;
			}
			
			if(1 == falseFlg)
			{
				break;
			}
		}
		
		// Disp result.
		if(0 == falseFlg)
		{
			printf("yes\n");
		}
		else
		{
			printf("no\n");
		}
	}while(1);
	
	return 0;
}

// CheckBracket
// Function  : Check to match bracket.
// Param[in] : char *bracketStr, int *bracketStrIdx, char inputStr
// Param[out]: 0(true) or 1(false)
// Global    : 
int CheckBracket(char *bracketStr, int *bracketStrIdx, char inputStr)
{
	char compareBracket = '\0';
	
	// If left-bracket is empty, falseFlg is 1.
	if(0 == *bracketStrIdx)
	{
		return 1;
	}
	
	// Select the compare bracket.
	if(')' == inputStr)
	{
		compareBracket = '(';
	}
	else
	{
		compareBracket = '[';
	}
	
	// Check to match bracket.
	if(compareBracket == bracketStr[(*bracketStrIdx) - 1])
	{
		bracketStr[(*bracketStrIdx) - 1] = '\0';
		(*bracketStrIdx)--;
	}
	else
	{
		return 1;
	}
	
	return 0;
}

// Test sting
/* ------------------------------------------------------------------------
So when I die (the [first] I will see in (heaven) is a score list).   yes
[ first in ] ( first out ).                                           yes
Half Moon tonight (At least it is better than no Moon at all].        no
A rope may form )( a trail in a maze.                                 no
Help( I[m being held prisoner in a fortune cookie factory)].          no
([ (([( [ ] ) ( ) (( ))] )) ]).                                       yes
 .                                                                    yes
.                                                                     
------------------------------------------------------------------------ */
